#include <stdio.h>
#include <windows.h>

#pragma aux NEWIP "*"

int APIENTRY LibMain( HANDLE hdll,
                      DWORD  reason,
                      LPVOID reserved )
{
    MessageBox( NULL, "Hello from LibMain of NEWIP.DLL", "DLL32", 
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

void NEWIP( float* fActual, float *fBound)
{
   char cBuff[128];
   sprintf( cBuff, "Hello from NEWIP: %g %g", *fActual, *fBound);
   MessageBox( NULL, cBuff, "NEWIP", 
     MB_ICONEXCLAMATION | MB_TASKMODAL | MB_OK);
}

