#pragma once
#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <tchar.h>

namespace SharedMemoryServer 
{
    TCHAR szName[] = TEXT("Global\\MyFileMappingObject"); // Global ID all processes started by windows users can access this memory to each other. Administrator permission is required. If this requirement is not met, the global ID can be omitted

    class SharedMemoryServer
    {
    private:
        LPCTSTR _p_buf;
        HANDLE _h_map_file;
    
    public:
        SharedMemoryServer(unsigned int size) 
        {
            _h_map_file = CreateFileMapping(
                INVALID_HANDLE_VALUE,    // use paging file
                NULL,                    // default security
                PAGE_READWRITE,          // read/write access
                0,                       // maximum object size (high-order DWORD)
                size,                // maximum object size (low-order DWORD)
                szName);                 // name of mapping object
    
            if (_h_map_file == NULL)
            {
                _tprintf(TEXT("Could not create file mapping object (%d).\n"),
                    GetLastError());
                exit(1);
            }
            _p_buf = (LPTSTR)MapViewOfFile(_h_map_file,   // handle to map object
                FILE_MAP_ALL_ACCESS, // read/write permission
                0,
                0,
                size);
    
            if (_p_buf == NULL)
            {
                _tprintf(TEXT("Could not map view of file (%d).\n"),
                    GetLastError());
    
                CloseHandle(_h_map_file);
    
                exit(1);
            }
        }

        char* GetBuf()
        {
            return (char*)_p_buf;
        }

        ~SharedMemoryServer()
        {
            UnmapViewOfFile(_p_buf);
            CloseHandle(_h_map_file);
        }
    };
}

//namespace SharedMemoryServer
//{
//#define BUF_SIZE 256 // describes the shared memory size
//    TCHAR szName[] = TEXT("Global\\MyFileMappingObject"); // Global ID all processes started by windows users can access this memory to each other. Administrator permission is required. If this requirement is not met, the global ID can be omitted
//    TCHAR szMsg[] = TEXT("Message from first process."); // data
//
//    int TestSharedMemoryServer()
//    {
//        HANDLE hMapFile;
//        LPCTSTR pBuf;
//
//        hMapFile = CreateFileMapping(
//            INVALID_HANDLE_VALUE,    // use paging file
//            NULL,                    // default security
//            PAGE_READWRITE,          // read/write access
//            0,                       // maximum object size (high-order DWORD)
//            BUF_SIZE,                // maximum object size (low-order DWORD)
//            szName);                 // name of mapping object
//
//        if (hMapFile == NULL)
//        {
//            _tprintf(TEXT("Could not create file mapping object (%d).\n"),
//                GetLastError());
//            return 1;
//        }
//        pBuf = (LPTSTR)MapViewOfFile(hMapFile,   // handle to map object
//            FILE_MAP_ALL_ACCESS, // read/write permission
//            0,
//            0,
//            BUF_SIZE);
//
//        if (pBuf == NULL)
//        {
//            _tprintf(TEXT("Could not map view of file (%d).\n"),
//                GetLastError());
//
//            CloseHandle(hMapFile);
//
//            return 1;
//        }
//
//        CopyMemory((PVOID)pBuf, szMsg, (_tcslen(szMsg) * sizeof(TCHAR)));
//        _getch();
//
//        UnmapViewOfFile(pBuf);
//
//        CloseHandle(hMapFile);
//
//        return 0;
//    }
//}