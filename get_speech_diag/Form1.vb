Imports System.Speech
Public Class Form1

    Dim WithEvents reco As New Speech.Recognition.SpeechRecognitionEngine()

    Private Sub Form1_Load(sender As Object, e As EventArgs) Handles MyBase.Load


        reco.SetInputToDefaultAudioDevice()
        'reco.SetInputToWaveFile("test.wav")

        Dim gram As New Recognition.SrgsGrammar.SrgsDocument

        Dim colorRule As New Recognition.SrgsGrammar.SrgsRule("color")
        'Dim numberRule As New Recognition.SrgsGrammar.SrgsRule("numbers")

        'Dim colorsList As New Recognition.SrgsGrammar.SrgsOneOf("red", "green", "blue", "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "over", "hello")
        'Dim numberList As New Recognition.SrgsGrammar.SrgsOneOf("zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine")
        Dim aiRuleList As New Recognition.SrgsGrammar.SrgsOneOf("send", "clear", "hi", "you", "red")

        colorRule.Add(aiRuleList)
        'numberRule.Add(numberList)
        'colorRule.Add(numberList)

        gram.Rules.Add(colorRule)
        'gram.Rules.Add(numberRule)

        gram.Root = colorRule

        reco.LoadGrammar(New Recognition.Grammar(gram))

        reco.RecognizeAsync()



    End Sub

    Private Sub reco_SpeechRecognized(ByVal sender As Object, ByVal e As System.Speech.Recognition.RecognitionEventArgs) Handles reco.SpeechRecognized

        If (e.Result.Text = "clear") Then
            TextBox1.Text = ""
        ElseIf (e.Result.Text = "send") Then
            Console.WriteLine(TextBox1.Text)
            Me.Close()
        End If

        TextBox1.Text += " " & e.Result.Text
    End Sub

    Private Sub reco_RecognizeCompleted(ByVal sender As Object, ByVal e As System.Speech.Recognition.RecognizeCompletedEventArgs) Handles reco.RecognizeCompleted

        reco.RecognizeAsync()

    End Sub


    Private Sub Button2_Click(sender As Object, e As EventArgs) Handles Button2.Click
        Console.WriteLine(TextBox1.Text)
        Me.Close()
    End Sub

    Private Sub Button1_Click(sender As Object, e As EventArgs) Handles Button1.Click
        TextBox1.Text = ""
    End Sub
End Class
