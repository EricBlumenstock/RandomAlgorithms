      program lindops

c-----------------------------------------------------------------------------
c
c A Microsoft Powerstation FORTRAN program to define and solve the 
c following model using the 32 bit LINDO Dynamic Link Library:
c 
c     Max 20 X + 30 Y
c     S.T.
c         X < 50
c         Y < 60
c         X + 2Y < 120
c     End
c
c-----------------------------------------------------------------------------

      implicit none

c lnspsint.h contains the definitions for all the LINDO callable routines

	include 'lndpsint.h'

c define variables

	character*8 kname
      integer*4 i, idrow, istat, irowx( 3), irowy( 3)
      logical trouble
      real obj, x, y, dual
      real rhs( 3), valx( 3), valy( 3)

c data initialization

      data rhs /50., 60., 120./
      data valx / 20., 1., 1./
      data valy / 30., 1., 2./						   
      data irowx /1,2,4/
      data irowy /1,3,4/

c Initialize LINDO by calling ILINDO and INIT.

      call ilindo
	call init

c Put LINDO in TERSE mode

	call quiet( -1)

c Call DEFROW to define objective row

      call defrow( -1, 0., idrow, trouble)

c Now, call DEFROW to define constraint rows

      do i = 1, 3
	   call defrow( 1, rhs( i), idrow, trouble)
      enddo

c Call APPCOL to define columns.  Note that all character data
c is passed using double indirection!

c Define X

      kname = 'X'
      call appcol( loc( kname), 3, valx, irowx, trouble)

c Define Y

      kname = 'Y'
      call appcol( loc( kname), 3, valy, irowy, trouble)

c Display the formulation

	call look( 1, 4)

c Call GO to solve the model

	call go( 1000, istat)

c Get the objective value

	call reprow( 1, obj, dual)
      
c Get the value of x

	call repvar( 1, x, dual)
      
c Get the value of y

	call repvar( 2, y, dual)

c Report values

      write(6,10) obj, x, y
   10 format(//,
     +'  Objective =',f8.1,/,'     X =',f8.1,/,'     Y =',f8.1,/)
      pause ' Press <Enter> to exit:'

c Shut down LINDO by calling LSEXIT

      call lsexit

c All Done

      end
