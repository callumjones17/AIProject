Imports System.Speech
Module EntryPoint
    Sub Main()
        If (My.Application.CommandLineArgs.Count = 0) Then
            Console.WriteLine("Wrong Arguments Given.")
        Else
            Dim speak As New Speech.Synthesis.SpeechSynthesizer
            speak.SelectVoiceByHints(Synthesis.VoiceGender.Male)
            speak.Speak(My.Application.CommandLineArgs(0))
        End If
    End Sub
End Module
