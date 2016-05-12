using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Diagnostics;

using TestingApp;

namespace TestingApp
{
    class Program
    {
        static void Main(string[] args)
        {
            Process p = new Process();
            p.StartInfo.UseShellExecute = false;
            p.StartInfo.RedirectStandardOutput = true;
            p.StartInfo.FileName = "AIProject.exe";
            string arg = "do you undehitand";
            arg = arg.Insert(0,"\"");
            arg = arg.Insert(arg.Length-1,"\"");
            p.StartInfo.Arguments = arg;
            p.Start();
            string outputP = p.StandardOutput.ReadToEnd();
            p.WaitForExit();
            Console.WriteLine(outputP);
            p.Close();


            //outputP = outputP.Insert(0, "\"");
            //outputP = outputP.Insert(outputP.Length - 1, "\"");
            Process espeak = new Process();
            p.StartInfo.FileName = "espeak.exe";
            p.StartInfo.Arguments = "-ven+mf4"  + outputP;
            p.Start();
            p.WaitForExit();
            p.Close();


            Console.ReadLine();
        }
    }
}
