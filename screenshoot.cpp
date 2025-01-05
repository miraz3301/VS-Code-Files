#include <windows.h>
#include <string>
#include <iostream>

// Function to capture a screenshot and save it as a BMP file
bool CaptureScreenshot(const std::string& filename) {
    // Get the desktop window
    HWND hwndDesktop = GetDesktopWindow();
    HDC hdcScreen = GetDC(hwndDesktop);
    HDC hdcMem = CreateCompatibleDC(hdcScreen);
    RECT desktopRect;
    GetWindowRect(hwndDesktop, &desktopRect);

    // Get the width and height of the screen
    int width = desktopRect.right;
    int height = desktopRect.bottom;

    // Create a compatible bitmap
    HBITMAP hbmScreen = CreateCompatibleBitmap(hdcScreen, width, height);
    SelectObject(hdcMem, hbmScreen);

    // Bit block transfer from the screen to the memory device context
    BitBlt(hdcMem, 0, 0, width, height, hdcScreen, 0, 0, SRCCOPY);

    // Set up BITMAPFILEHEADER and BITMAPINFOHEADER
    BITMAPFILEHEADER bmfHeader;
    BITMAPINFOHEADER bi;

    bi.biSize = sizeof(BITMAPINFOHEADER);
    bi.biWidth = width;
    bi.biHeight = -height; // Negative height to create a top-down DIB
    bi.biPlanes = 1;
    bi.biBitCount = 32;
    bi.biCompression = BI_RGB;
    bi.biSizeImage = 0;
    bi.biXPelsPerMeter = 0;
    bi.biYPelsPerMeter = 0;
    bi.biClrUsed = 0;
    bi.biClrImportant = 0;

    DWORD dwBmpSize = ((width * bi.biBitCount + 31) / 32) * 4 * height;

    // Allocate memory for bitmap
    HANDLE hDIB = GlobalAlloc(GHND, dwBmpSize);
    char* lpbitmap = (char*)GlobalLock(hDIB);

    // Retrieve the bitmap color data
    GetDIBits(hdcScreen, hbmScreen, 0, height, lpbitmap, (BITMAPINFO*)&bi, DIB_RGB_COLORS);

    // Open the file to save the screenshot
    HANDLE hFile = CreateFile(filename.c_str(), GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

    DWORD dwSizeofDIB = dwBmpSize + sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);

    // Add the size of headers to the bitmap file header
    bmfHeader.bfOffBits = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);
    bmfHeader.bfSize = dwSizeofDIB;
    bmfHeader.bfType = 0x4D42; // BM

    DWORD dwBytesWritten;
    // Write the file header
    WriteFile(hFile, (LPSTR)&bmfHeader, sizeof(BITMAPFILEHEADER), &dwBytesWritten, NULL);
    // Write the bitmap info header
    WriteFile(hFile, (LPSTR)&bi, sizeof(BITMAPINFOHEADER), &dwBytesWritten, NULL);
    // Write the bitmap color data
    WriteFile(hFile, (LPSTR)lpbitmap, dwBmpSize, &dwBytesWritten, NULL);

    // Unlock and free memory
    GlobalUnlock(hDIB);
    GlobalFree(hDIB);

    // Close the file
    CloseHandle(hFile);

    // Clean up
    DeleteObject(hbmScreen);
    DeleteDC(hdcMem);
    ReleaseDC(hwndDesktop, hdcScreen);

    return true;
}

int main() {
    std::string filename = "screenshot.bmp";
    if (CaptureScreenshot(filename)) {
        std::cout << "Screenshot saved as " << filename << std::endl;
    } else {
        std::cout << "Failed to capture screenshot" << std::endl;
    }
    return 0;
}
