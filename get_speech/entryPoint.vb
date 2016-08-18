Imports System.Speech
Module entryPoint

    Dim WithEvents reco As New Recognition.SpeechRecognitionEngine
    Dim SpeechRecognised As Boolean = False

    Sub Main()

        reco.SetInputToDefaultAudioDevice()
        Dim gram As New Recognition.SrgsGrammar.SrgsDocument
        Dim aiRule As New Recognition.SrgsGrammar.SrgsRule("keywords")
        Dim aiRuleList As New Recognition.SrgsGrammar.SrgsOneOf("red", "hello", "hi", "you")
        aiRule.Add(aiRuleList)
        gram.Rules.Add(aiRule)
        gram.Root = aiRule
        reco.LoadGrammar(New Recognition.Grammar(gram))
        reco.RecognizeAsync()
        Do Until SpeechRecognised

        Loop

    End Sub

    Private Sub reco_SpeechRecognized(ByVal sender As Object, ByVal e As System.Speech.Recognition.RecognitionEventArgs) Handles reco.SpeechRecognized
        Console.WriteLine(e.Result.Text)
        SpeechRecognised = True
    End Sub


End Module
