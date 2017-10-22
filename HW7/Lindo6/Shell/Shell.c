
#include <stdio.h>      // for file i/o
#include <io.h>         // for dup functions
#include <process.h>    // for spawn function

void main()
{
	char *cFileIn   = "C:\\LINDO\\LNDIN.TXT";
	char *cFileOut  = "C:\\LINDO\\LNDOUT.TXT";
	char *cFileSolu = "C:\\LINDO\\SOLUTION.TXT";
    float fXVal, fYVal;
	FILE *fp, *fpIn, *fpOut, *fpSolution;
	int nStdIn, nStdOut;

// Open a LINDO script file
    fp = fopen( cFileIn, "w");

// Always a good idea to do a PAGE 0 first off in LINDO script files
    fprintf( fp, "PAGE 0\n");

// Send the formulation to the script file
	fprintf( fp, "MAX 20X+30Y\n");
	fprintf( fp, "ST\n");
	fprintf( fp, "X<50\n");
	fprintf( fp, "Y<60\n");
	fprintf( fp, "X+2Y<120\n");
	fprintf( fp, "END\n");

// Supress the standard solution report
    fprintf( fp, "TERSE\n");

// Solve the model
    fprintf( fp, "GO\n");

// Open a file for storing the solution
    fprintf( fp, "DIVERT %s\n", cFileSolu);

// Send the solution to the output file
    fprintf( fp, "CPRI /N P\n");

// Close output file
    fprintf( fp, "RVRT\n");

// Quit LINDO
    fprintf( fp, "QUIT\n");

// Close LINDO command file
    fclose( fp);

// Redirect standard input to the script file
	nStdIn = dup( 0);
	fpIn = fopen( cFileIn, "r");
	dup2( fileno( fpIn), 0);

// Redirect standard output to a file
	nStdOut = dup( 1);
	fpOut = fopen( cFileOut, "w");
	dup2( fileno( fpOut), 1);

// Run LINDO and process script file.
	spawnlp( P_WAIT, "C:\\LINDO\\LINDO.EXE", " ", NULL);

// Flush i/o streams
	fflush( stdin);
	fflush( stdout);

// Restore standard i/o
	dup2( nStdIn, 0);
	dup2( nStdOut, 1);

// Close files
	fclose( fpIn);
	fclose( fpOut);

// Open solution file
	fpSolution = fopen( cFileSolu, "rt");

// Display the solution
	fscanf( fpSolution, "%f\n%f", &fXVal, &fYVal);
	printf("X and Y = %f %f\n", fXVal, fYVal);

// Close solution file
	fclose( fpSolution);
}

