Imports System.Speech
Module EntryPoint
    Sub Main()
        If (My.Application.CommandLineArgs.Count = 1) Then
            Dim speak As Speech.Synthesis.SpeechSynthesizer = New Synthesis.SpeechSynthesizer()
            speak.SelectVoiceByHints(Synthesis.VoiceGender.Male)
            speak.SpeakAsync(My.Application.CommandLineArgs(0))
        Else
            Console.WriteLine("Wrong Arguments Given.")
        End If
    End Sub
End Module
