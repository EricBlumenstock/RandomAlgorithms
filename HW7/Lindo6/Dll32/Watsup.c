#include <stdio.h>
#include <windows.h>

#pragma aux WATSUP "*"

int APIENTRY LibMain( HANDLE hdll,
                      DWORD  reason,
                      LPVOID reserved )
{
    MessageBox( NULL, "Hello from LibMain of WATSUP.DLL", "WATSUP", 
     MB_ICONEXCLAMATION | MB_TASKMODAL | MB_OK);

    switch( reason ) {
    case DLL_THREAD_ATTACH:
        /* do thread initialization */
        break;
    case DLL_THREAD_DETACH:
        /* do thread cleanup */

        break;
    case DLL_PROCESS_ATTACH:
        /* do process initialization */
        break;
    case DLL_PROCESS_DETACH:
        /* do process cleanup */
        break;
    }
    return( 1 );        /* indicate success */
    /* returning 0 indicates initialization failure */
}

void WATSUP( float fEnviron[], long lStatus[])
{
   char cBuff[128];
   sprintf( cBuff, "Hello from WATSUP iter, obj: %d %g", lStatus[1], fEnviron[1]);
   MessageBox( NULL, cBuff, "WATSUP", 
     MB_ICONEXCLAMATION | MB_TASKMODAL | MB_OK);
}

