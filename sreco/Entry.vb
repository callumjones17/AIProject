Imports SpeechLib




Public Class Entry

    Public WithEvents RC As SpSharedRecoContext
    Public myGrammar As ISpeechRecoGrammar

    Sub Main()
        On Error GoTo EH

        RC = New SpSharedRecoContext

        myGrammar = RC.CreateGrammar
        'myGrammar.DictationSetState(SGDSActive)
        myGrammar.DictationSetState(SpeechRuleState.SGDSActive)

EH:
        If Err.Number Then ShowErrMsg()
    End Sub

    Private Sub RC_Recognition(ByVal StreamNumber As Long, ByVal StreamPosition As Object, ByVal RecognitionType As SpeechLib.SpeechRecognitionType, ByVal Result As SpeechLib.ISpeechRecoResult)
        'Label1.Caption = Result.PhraseInfo.GetText
    End Sub

    Private Sub RC_StartStream(ByVal StreamNumber As Long, ByVal StreamPosition As Object)
        'Label2.Caption = Val(StreamNumber)
    End Sub

    Private Sub ShowErrMsg()

        ' Declare identifiers:
        Const NL = vbNewLine
        Dim T As String

        T = "Desc: " & Err.Description & NL
        T = T & "Err #: " & Err.Number
        MsgBox(T, vbExclamation, "Run-Time Error")
    End Sub


End Class
