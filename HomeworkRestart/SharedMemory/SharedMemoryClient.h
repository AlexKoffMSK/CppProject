#pragma once
#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <tchar.h>
#pragma comment(lib, "user32.lib")

namespace SharedMemoryClient
{
    TCHAR szName[] = TEXT("Global\\MyFileMappingObject"); // Global ID all processes started by windows users can access this memory to each other. Administrator permission is required. If this requirement is not met, the global ID can be omitted

    class SharedMemoryClient
    {
    private:
        LPCTSTR _p_buf;
        HANDLE _h_map_file;

    public:
        SharedMemoryClient(unsigned int size)
        {
            _h_map_file = OpenFileMapping(
                FILE_MAP_ALL_ACCESS,   // read/write access
                FALSE,                 // do not inherit the name
                szName);               // name of mapping object

            if (_h_map_file == NULL)
            {
                _tprintf(TEXT("Could not open file mapping object (%d).\n"),
                    GetLastError());
                exit(1);
            }

            _p_buf = (LPTSTR)MapViewOfFile(_h_map_file, // handle to map object
                FILE_MAP_ALL_ACCESS,  // read/write permission
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

        ~SharedMemoryClient()
        {
            UnmapViewOfFile(_p_buf);
            CloseHandle(_h_map_file);
        }
    };
}

//namespace SharedMemoryClient 
//{
//#define BUF_SIZE 256
//    TCHAR szName[] = TEXT("Global\\MyFileMappingObject");
//
//    int TestSharedMemoryClient()
//    {
//        HANDLE hMapFile;
//        LPCTSTR pBuf;
//
//        hMapFile = OpenFileMapping(
//            FILE_MAP_ALL_ACCESS,   // read/write access
//            FALSE,                 // do not inherit the name
//            szName);               // name of mapping object
//
//        if (hMapFile == NULL)
//        {
//            _tprintf(TEXT("Could not open file mapping object (%d).\n"),
//                GetLastError());
//            return 1;
//        }
//
//        pBuf = (LPTSTR)MapViewOfFile(hMapFile, // handle to map object
//            FILE_MAP_ALL_ACCESS,  // read/write permission
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
//        MessageBox(NULL, pBuf, TEXT("Process2"), MB_OK);
//
//        UnmapViewOfFile(pBuf);
//
//        CloseHandle(hMapFile);
//
//        return 0;
//    }
//}