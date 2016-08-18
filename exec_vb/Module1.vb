Module Module1

    Sub Main()

        If My.Application.CommandLineArgs.Count = 0 Then
            Console.WriteLine("No File Given!")
        Else


            Dim p As System.Diagnostics.Process = New Process()
            With p
                .StartInfo.FileName = My.Application.CommandLineArgs(0)
            End With
            Try
                p.Start()
            Catch ex As Exception
                Console.WriteLine(ex.Message)
            End Try

        End If
    End Sub

End Module
