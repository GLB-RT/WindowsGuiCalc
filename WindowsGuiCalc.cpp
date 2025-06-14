// WindowsProject2.cpp : Defines the entry point for the application.
//

#include "framework.h"
#include "WindowsGuiCalc.h"

#define MAX_LOADSTRING 100
#define ID_PRZYCISK1 501
#define ID_PRZYCISK2 502
#define ID_PRZYCISK3 503
#define ID_PRZYCISK4 504
#define ID_PRZYCISK5 505
#define ID_PRZYCISK6 506
#define ID_PRZYCISK7 507
#define ID_PRZYCISK8 508
#define ID_PRZYCISK9 509
#define ID_PRZYCISKPLUS 510
#define ID_PRZYCISKDIVIDE 511
#define ID_PRZYCISKMULTI 512
#define ID_PRZYCISKEQUAL 513

// Global variables:
HINSTANCE hInst;                                // Current application instance
WCHAR szTitle[100];                             // Window title text
WCHAR szWindowClass[MAX_LOADSTRING];            // Main window class name

// Function declarations used in this code module:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);
HWND g_hPrzycisk1; // Global handle to button
HWND g_hPrzycisk2; // Global handle to button
HWND g_hPrzycisk3; // Global handle to button
HWND g_hPrzycisk4; // Global handle to button
HWND g_hPrzycisk5; // Global handle to button
HWND g_hPrzycisk6; // Global handle to button
HWND g_hPrzycisk7; // Global handle to button
HWND g_hPrzycisk8; // Global handle to button
HWND g_hPrzycisk9; // Global handle to button
HWND g_hPrzyciskPlus; // Global handle to button
HWND g_hPrzyciskMinus; // Global handle to button
HWND g_hPrzyciskDivide; // Global handle to button
HWND g_hPrzyciskMulti; // Global handle to button
HWND g_hPrzyciskEqual; // Global handle to button
HWND g_hLabel; // Handle to label (calculator display)

// Main application function WinMain (entry point)
int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPWSTR    lpCmdLine,
    _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance); // Unused variable
    UNREFERENCED_PARAMETER(lpCmdLine);     // Unused variable

    // TODO: Place application code here.

    // Initialize global string variables
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING); // Load application title
    LoadStringW(hInstance, IDC_WINDOWSGUICALC, szWindowClass, MAX_LOADSTRING); // Load window class name
    MyRegisterClass(hInstance); // Register window class

    // Application initialization:
    if (!InitInstance(hInstance, nCmdShow))
    {
        return FALSE; // Exit if instance initialization failed
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WINDOWSGUICALC)); // Load accelerators (keyboard shortcuts)

    MSG msg; // Message structure

    // Main message loop:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        // If the message was not handled by accelerators, pass it on
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg); // Translate message
            DispatchMessage(&msg);  // Send message to the appropriate window procedure
        }
    }

    return (int)msg.wParam; // Return application exit code
}

//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX); // Structure size

    wcex.style = CS_HREDRAW | CS_VREDRAW; // Window class style (redraw on resize)
    wcex.lpfnWndProc = WndProc;                 // Pointer to window procedure
    wcex.cbClsExtra = 0;                       // Extra bytes for class
    wcex.cbWndExtra = 0;                       // Extra bytes for window
    wcex.hInstance = hInstance;               // Application instance handle
    wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WINDOWSGUICALC)); // Application icon
    wcex.hCursor = LoadCursor(nullptr, IDC_ARROW); // Mouse cursor
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);       // Window background color
    wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_WINDOWSGUICALC); // Menu name
    wcex.lpszClassName = szWindowClass;                   // Window class name
    wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL)); // Small icon

    return RegisterClassExW(&wcex); // Register window class
}

//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves the instance handle and creates the main window
//
//   NOTES:
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
    hInst = hInstance; // Save instance handle in global variable

    // Set window dimensions
    int width = 550;
    int height = 370;

    // Create the main application window
    HWND hWnd = CreateWindowW(
        szWindowClass,
        szTitle,
        WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX, // fixed size, not resizable
        CW_USEDEFAULT, CW_USEDEFAULT,
        width, height,
        nullptr, nullptr,
        hInstance, nullptr);

    if (!hWnd)
    {
        return FALSE; // Return FALSE if window creation failed
    }

    ShowWindow(hWnd, nCmdShow); // Show window
    UpdateWindow(hWnd);         // Refresh window
    SetMenu(hWnd, NULL); // Remove menu

    g_hPrzycisk1 = CreateWindowEx(
        0,
        L"BUTTON",
        L"1",
        WS_CHILD | WS_VISIBLE | BS_DEFPUSHBUTTON,
        50, 50,
        50, 50,
        hWnd,
        (HMENU)ID_PRZYCISK1,
        hInstance,
        NULL
    );

    g_hPrzycisk2 = CreateWindowEx(
        0,
        L"BUTTON",
        L"2",
        WS_CHILD | WS_VISIBLE | BS_DEFPUSHBUTTON,
        50, 110,
        50, 50,
        hWnd,
        (HMENU)ID_PRZYCISK2,
        hInstance,
        NULL
    );

    g_hPrzycisk3 = CreateWindowEx(
        0,
        L"BUTTON",
        L"3",
        WS_CHILD | WS_VISIBLE | BS_DEFPUSHBUTTON,
        50, 170,
        50, 50,
        hWnd,
        (HMENU)ID_PRZYCISK2,
        hInstance,
        NULL
    );

    g_hPrzycisk4 = CreateWindowEx(
        0,
        L"BUTTON",
        L"4",
        WS_CHILD | WS_VISIBLE | BS_DEFPUSHBUTTON,
        110, 50,
        50, 50,
        hWnd,
        (HMENU)ID_PRZYCISK2,
        hInstance,
        NULL
    );

    g_hPrzycisk5 = CreateWindowEx(
        0,
        L"BUTTON",
        L"5",
        WS_CHILD | WS_VISIBLE | BS_DEFPUSHBUTTON,
        110, 110,
        50, 50,
        hWnd,
        (HMENU)ID_PRZYCISK2,
        hInstance,
        NULL
    );

    g_hPrzycisk6 = CreateWindowEx(
        0,
        L"BUTTON",
        L"6",
        WS_CHILD | WS_VISIBLE | BS_DEFPUSHBUTTON,
        110, 170,
        50, 50,
        hWnd,
        (HMENU)ID_PRZYCISK2,
        hInstance,
        NULL
    );

    g_hPrzycisk7 = CreateWindowEx(
        0,
        L"BUTTON",
        L"7",
        WS_CHILD | WS_VISIBLE | BS_DEFPUSHBUTTON,
        170, 50,
        50, 50,
        hWnd,
        (HMENU)ID_PRZYCISK2,
        hInstance,
        NULL
    );

    g_hPrzycisk8 = CreateWindowEx(
        0,
        L"BUTTON",
        L"8",
        WS_CHILD | WS_VISIBLE | BS_DEFPUSHBUTTON,
        170, 110,
        50, 50,
        hWnd,
        (HMENU)ID_PRZYCISK2,
        hInstance,
        NULL
    );

    g_hPrzycisk9 = CreateWindowEx(
        0,
        L"BUTTON",
        L"9",
        WS_CHILD | WS_VISIBLE | BS_DEFPUSHBUTTON,
        170, 170,
        50, 50,
        hWnd,
        (HMENU)ID_PRZYCISK2,
        hInstance,
        NULL
    );

    g_hPrzyciskPlus = CreateWindowEx(
        0,
        L"BUTTON",
        L"+",
        WS_CHILD | WS_VISIBLE | BS_DEFPUSHBUTTON,
        230, 50,
        50, 50,
        hWnd,
        (HMENU)ID_PRZYCISK2,
        hInstance,
        NULL
    );

    g_hPrzyciskMinus = CreateWindowEx(
        0,
        L"BUTTON",
        L"-",
        WS_CHILD | WS_VISIBLE | BS_DEFPUSHBUTTON,
        230, 110,
        50, 50,
        hWnd,
        (HMENU)ID_PRZYCISK2,
        hInstance,
        NULL
    );

    g_hPrzyciskDivide = CreateWindowEx(
        0,
        L"BUTTON",
        L"/",
        WS_CHILD | WS_VISIBLE | BS_DEFPUSHBUTTON,
        230, 170,
        50, 50,
        hWnd,
        (HMENU)ID_PRZYCISK2,
        hInstance,
        NULL
    );

    g_hPrzyciskMulti = CreateWindowEx(
        0,
        L"BUTTON",
        L"*",
        WS_CHILD | WS_VISIBLE | BS_DEFPUSHBUTTON,
        230, 230,
        50, 50,
        hWnd,
        (HMENU)ID_PRZYCISK2,
        hInstance,
        NULL
    );

    g_hPrzyciskEqual = CreateWindowEx(
        0,
        L"BUTTON",
        L"=",
        WS_CHILD | WS_VISIBLE | BS_DEFPUSHBUTTON,
        50, 230,
        170, 50,
        hWnd,
        (HMENU)ID_PRZYCISK2,
        hInstance,
        NULL
    );

    g_hLabel = CreateWindowW(
        L"STATIC",
        L"0", // Initial text
        WS_CHILD | WS_VISIBLE | SS_RIGHT | WS_BORDER,
        300, 50,
        200, 50,
        hWnd,
        (HMENU)1001,
        hInstance,
        NULL
    );

    return TRUE; // Return TRUE if everything succeeded
}

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE: Processes messages for the main window.
//
//  WM_COMMAND  - handle application menu
//  WM_PAINT    - paint the main window
//  WM_DESTROY  - post a quit message
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
    {
        int wmId = LOWORD(wParam); // Get command identifier from menu
        // Handle menu selections:
        switch (wmId)
        {
        case IDM_ABOUT:
            DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About); // Show "About" dialog
            break;
        case IDM_EXIT:
            DestroyWindow(hWnd); // Close main window
            break;
        case ID_PRZYCISK1:
            MessageBox(hWnd, L"You pressed the button!", L"Information", MB_OK | MB_ICONINFORMATION);
            break;
        case ID_PRZYCISK2:
            MessageBox(hWnd, L"You pressed button number 2!", L"Information", MB_OK | MB_ICONINFORMATION);
            break;

        default:
            return DefWindowProc(hWnd, message, wParam, lParam); // Default handling
        }
    }
    break;
    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hWnd, &ps); // Begin painting
        // TODO: Add drawing code here using hdc...
        EndPaint(hWnd, &ps); // End painting
    }
    break;
    case WM_DESTROY:
        PostQuitMessage(0); // Post quit message
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam); // Default handling for other messages
    }

    return 0;
}

// "About" dialog window procedure
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam); // Unused variable
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE; // Dialog initialization

    case WM_COMMAND:
        // Close dialog on OK or Cancel
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE; // Default handling
}