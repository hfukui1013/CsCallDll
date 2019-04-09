using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using Hello;

namespace CsCallDll
{
	class Program
	{
		[System.Runtime.InteropServices.DllImport("Win32Project1.dll")]
		static extern int FunctionName(int x, int y);

		static void Main(string[] args)
		{
			Console.WriteLine("2 + 3 = {0}", FunctionName(2, 3));

			ManagedClass mc = new ManagedClass();
			Console.WriteLine("1 + 4 = {0}", mc.Add(1, 4));

		}
	}
}
