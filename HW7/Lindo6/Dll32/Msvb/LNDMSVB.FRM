VERSION 5.00
Begin VB.Form Form1 
   Caption         =   "LINDO/Visual Basic 5.0 Example"
   ClientHeight    =   3195
   ClientLeft      =   60
   ClientTop       =   345
   ClientWidth     =   4680
   LinkTopic       =   "Form1"
   ScaleHeight     =   3195
   ScaleWidth      =   4680
   StartUpPosition =   3  'Windows Default
   Begin VB.CommandButton Quit 
      Caption         =   "Quit"
      Height          =   615
      Left            =   3120
      TabIndex        =   1
      Top             =   1320
      Width           =   1335
   End
   Begin VB.CommandButton Solve 
      Caption         =   "Solve"
      Height          =   615
      Left            =   3120
      TabIndex        =   0
      Top             =   480
      Width           =   1335
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Declare Sub APPCOL Lib "lnddll32.dll" Alias "APPCOLX_STD" (ByVal Kname As String, Nonz As Long, Value As Single, Idrow As Long, Trouble As Long)
Private Declare Sub BINVT Lib "lnddll32.dll" Alias "BINVT_STD" (Dda As Double)
Private Declare Sub CAPOUT Lib "lnddll32.dll" Alias "CAPOUT_STD" (Unit As Long)
Private Declare Sub CLRBAS Lib "lnddll32.dll" Alias "CLRBAS_STD" ()
Private Declare Sub D2DMY Lib "lnddll32.dll" Alias "D2DMY_STD" (Ns1800 As Long, Nday As Long, Mon As Long, Nyr As Long)
Private Declare Sub DEFROW Lib "lnddll32.dll" Alias "DEFROW_STD" (Idir As Long, Rhs As Single, Idrow As Long, Trouble As Long)
Private Declare Sub DELCON Lib "lnddll32.dll" Alias "DELCON_STD" (I As Long)
Private Declare Sub DMY2D Lib "lnddll32.dll" Alias "DMY2D_STD" (Nday As Long, Mon As Long, Nyr As Long, Ns1800 As Long, Ndofwk As Long)
Private Declare Sub DRPVAR Lib "lnddll32.dll" Alias "DRPVAR_STD" (J As Long, Primal As Double, Dual As Double)
Private Declare Sub FPRIME Lib "lnddll32.dll" Alias "FPRIME_STD" (N1 As Long, N2 As Long)
Private Declare Sub FREEIT Lib "lnddll32.dll" Alias "FREEIT_STD" (J As Long)
Private Declare Sub GETCOL Lib "lnddll32.dll" Alias "GETCOLX_STD" (J As Long, ByVal Kname As String, Nonz As Long, Valx As Single, Iro As Long, Subj As Single, Truble As Long)
Private Declare Sub GO Lib "lnddll32.dll" Alias "GO_STD" (Limgo As Long, Istat As Long)
Private Declare Sub HEAPFR Lib "lnddll32.dll" Alias "HEAPFR_STD" (N As Long, M As Long, Index As Long, Nval As Long)
Private Declare Sub HEAPIT Lib "lnddll32.dll" Alias "HEAPIT_STD" (N As Long, M As Long, Index As Long, Nval As Long)
Private Declare Sub ILINDO Lib "lnddll32.dll" Alias "ILINDO_STD" ()
Private Declare Sub INIT Lib "lnddll32.dll" Alias "INIT_STD" ()
Private Declare Sub INSERT Lib "lnddll32.dll" Alias "INSERT_STD" (I As Long, J As Long, Amt As Single, Noadd As Long)
Private Declare Sub INSROW Lib "lnddll32.dll" Alias "INSROW_STD" (I As Long, Nonz As Long, Lstcol As Long, Valist As Single)
Private Declare Sub INVPRM Lib "lnddll32.dll" Alias "INVPRM_STD" (N As Long, Iperm As Long)
Private Declare Sub KLOSE Lib "lnddll32.dll" Alias "KLOSE_STD" (Lunit As Long)
Private Declare Sub LOOK Lib "lnddll32.dll" Alias "LOOK_STD" (Row1 As Long, Row2 As Long)
Private Declare Sub LSALTN Lib "lnddll32.dll" Alias "LSALTNX_STD" (Irtcod As Long, ByVal Ktext As String, J1 As Long, J2 As Long, Inrow As Long)
Private Declare Sub LSAVPR Lib "lnddll32.dll" Alias "LSAVPRX_STD" (Dz As Double, Memdz As Long, ByVal Kz As String, Memkz As Long, Irtcod As Long)
Private Declare Sub LSCTTN Lib "lnddll32.dll" Alias "LSCTTN_STD" ()
Private Declare Sub LSDMPS Lib "lnddll32.dll" Alias "LSDMPS_STD" (Lunit As Long)
Private Declare Sub LSEXIT Lib "lnddll32.dll" Alias "LSEXIT_STD" ()
Private Declare Sub LSFETP Lib "lnddll32.dll" Alias "LSFETP_STD" (Derr As Double, Iparam As Long, Dval As Double)
Private Declare Sub LSGTPR Lib "lnddll32.dll" Alias "LSGTPRX_STD" (Dz As Double, ByVal Kz As String, Irtcod As Long)
Private Declare Sub LSGTRO Lib "lnddll32.dll" Alias "LSGTRO_STD" (Irow As Long, Nnzmx As Long, Nnz As Long, Cof As Single, Iscol As Long)
Private Declare Sub LSINSR Lib "lnddll32.dll" Alias "LSINSR_STD" (Lunit As Long)
Private Declare Sub LSPUNC Lib "lnddll32.dll" Alias "LSPUNCX_STD" (Lunit As Long, ByVal XDATA As String)
Private Declare Sub LSPUTP Lib "lnddll32.dll" Alias "LSPUTP_STD" (Derr As Double, Iparam As Long, Dval As Double)
Private Declare Sub LUNGET Lib "lnddll32.dll" Alias "LUNGET_STD" (Lunit As Long, Inrout As Long, Notfmt As Long)
Private Declare Sub LUNOPN Lib "lnddll32.dll" Alias "LUNOPNX_STD" (Lunit As Long, Lfname As Long, ByVal Kfname As String, Inrout As Long, Notfmt As Long, Lutrmi As Long, Lutrmo As Long)
Private Declare Sub LXBRED Lib "lnddll32.dll" Alias "LXBRED_STD" (Lunit As Long, Inerr As Long)
Private Declare Sub LXBWRT Lib "lnddll32.dll" Alias "LXBWRT_STD" (Lunit As Long, Inerr As Long)
Private Declare Sub MAKINT Lib "lnddll32.dll" Alias "MAKINT_STD" (J As Long)
Private Declare Sub NDXOFV Lib "lnddll32.dll" Alias "NDXOFVX_STD" (ByVal Kline As String, I1 As Long, I2 As Long, J As Long)
Private Declare Sub NINTEQ Lib "lnddll32.dll" Alias "NINTEQ_STD" (Noint As Long)
Private Declare Sub OUTSPC Lib "lnddll32.dll" Alias "OUTSPC_STD" (K As Long)
Private Declare Sub PARBGN Lib "lnddll32.dll" Alias "PARBGN_STD" (K As Long, Paml As Single)
Private Declare Sub PARSTP Lib "lnddll32.dll" Alias "PARSTP_STD" (Piv As Single, Ji As Long, Jo As Long)
Private Declare Sub QUIET Lib "lnddll32.dll" Alias "QUIET_STD" (J As Long)
Private Declare Sub RDBC Lib "lnddll32.dll" Alias "RDBC_STD" (Lunit As Long)
Private Declare Sub RDMPS Lib "lnddll32.dll" Alias "RDMPS_STD" (Lunit As Long, Ndir As Long)
Private Declare Sub REPROW Lib "lnddll32.dll" Alias "REPROW_STD" (I As Long, Primal As Single, Dual As Single)
Private Declare Sub REPVAR Lib "lnddll32.dll" Alias "REPVAR_STD" (I As Long, Primal As Single, Dual As Single)
Private Declare Sub RETR Lib "lnddll32.dll" Alias "RETR_STD" (Lunit As Long)
Private Declare Sub RNGBGN Lib "lnddll32.dll" Alias "RNGBGN_STD" ()
Private Declare Sub RNGCOL Lib "lnddll32.dll" Alias "RNGCOL_STD" (J As Long, Cobj As Single, Tu As Single, Td As Single)
Private Declare Sub RNGROW Lib "lnddll32.dll" Alias "RNGROW_STD" (I As Long, Rhs As Single, Tu As Single, Td As Single)
Private Declare Sub SAVE Lib "lnddll32.dll" Alias "SAVE_STD" (Lunit As Long)
Private Declare Sub SDBC Lib "lnddll32.dll" Alias "SDBC_STD" (Lunit As Long)
Private Declare Sub SETIPT Lib "lnddll32.dll" Alias "SETIPT_STD" (Tol As Single)
Private Declare Sub SETQCP Lib "lnddll32.dll" Alias "SETQCP_STD" (J As Long)
Private Declare Sub SETSLB Lib "lnddll32.dll" Alias "SETSLB_STD" (J As Long, Slb As Single)
Private Declare Sub SETSUB Lib "lnddll32.dll" Alias "SETSUB_STD" (J As Long, TheSub As Single)
Private Declare Sub STATS Lib "lnddll32.dll" Alias "STATS_STD" (Idtail As Long)

Private Sub Quit_Click()
   End
End Sub

Private Sub Solve_Click()

' A simple Visual Basic 5.0 program to define
' and solve the following model using the 32
' bit LINDO DLL:
'
'    Max 20 X + 30 Y
'    S.T.
'        X < 50
'        Y < 60
'        X + 2Y < 120
'    End

   Dim Nonz As Long, Istat As Long
   Dim I As Long, Idir As Long
   Dim Trouble As Long, Idrow As Long
   Static Iro(3) As Long
   Dim Primal As Single, Dual As Single
   Static Rhs(3) As Single
   Static Value(3) As Single
   Dim Kname As String

' Initialize LINDO

   Call ILINDO
   Call INIT

' Redirect LINDO's standard output to a file

   Call LUNOPN(60, 9, "LINDO.OUT", _
    0, 0, 0, 0)
   Call CAPOUT(60)

' Put LINDO in TERSE model (note: not
' generally good practice until your
' app is fully debugged)

   Call QUIET(0)

' Define objective row

   Call DEFROW(-1, 0#, Idrow, Trouble)

' Define constraint rows
   
   Rhs(1) = 50: Rhs(2) = 60: Rhs(3) = 120
   For I = 1 To 3
      Call DEFROW(1, Rhs(I), Idrow, Trouble)
   Next I

' Define column "X"

   Iro(1) = 1: Iro(2) = 2: Iro(3) = 4
   Value(1) = 20: Value(2) = 1: Value(3) = 1
   Kname = "X       "
   Nonz = 3
   Call APPCOL(Kname, Nonz, Value(1), _
    Iro(1), Trouble)

' Define column "Y"

   Iro(1) = 1: Iro(2) = 3: Iro(3) = 4
   Value(1) = 30: Value(2) = 1: Value(3) = 2
   Kname = "Y       "
   Nonz = 3
   Call APPCOL(Kname, Nonz, Value(1), _
    Iro(1), Trouble)

' Solve the model

   Call GO(0, Istat)

' Print objective value

   I = 1
   Call REPROW(I, Primal, Dual)
   Print "   Objective Value:", Primal

' Print variable values

   Call REPVAR(1, Primal, Dual)
   Print ""
   Print "   X = ", Primal
   Call REPVAR(2, Primal, Dual)
   Print "   Y = ", Primal

' Shut down LINDO

   Call LSEXIT

End Sub
