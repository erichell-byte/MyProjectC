using System;
using System.IO;

  
       
string name;
string path = @"/Users/erichell/c#/day00/day00_ex01/name.txt";
Console.WriteLine("Enter name:");
name = Console.ReadLine();
if (name == "")
	Console.WriteLine("Your name was not found.");
else
{
	StreamReader sr = new StreamReader(path, System.Text.Encoding.Default);
	string line;
		while ((line = sr.ReadLine()) != null)
		{	
			int diff = LevenshteinDistance(name, line);
			if (diff == 0)
			{
				Console.WriteLine("Hello, {0}", line);
				break;
			}
			else if (diff <= 2)
			{
				Console.WriteLine("Did you mean {0}? y/n", line);
				string answer = Console.ReadLine();
				if (answer == "y")
				{
					Console.WriteLine("Hello, {0}", line);
					break;
				}
				else if (answer == "n")
				{
					if (diff >= 3 || line == null)
					{
						Console.WriteLine("Your name was not found.");
						break;
					}
					// Console.WriteLine("Did you mean {0}? y/n", line);
				}
				
			}
		}
		if ((line = sr.ReadLine()) == null)
			Console.WriteLine("Your name was not found.");

}

static int LevenshteinDistance(string string1, string string2)
{
	if (string1 == null) throw new ArgumentNullException("string1");
	if (string2 == null) throw new ArgumentNullException("string2");
	int diff;
	int[,] m = new int[string1.Length + 1, string2.Length + 1];

	for (int i = 0; i <= string1.Length; i++) { m[i, 0] = i; }
	for (int j = 0; j <= string2.Length; j++) { m[0, j] = j; }
	
	for (int i = 1; i <= string1.Length; i++)
	{
		for (int j = 1; j <= string2.Length; j++)
		{
			diff = (string1[i - 1] == string2[j - 1]) ? 0 : 1;

			m[i, j] = Math.Min(Math.Min(m[i - 1, j] + 1, m[i, j - 1] + 1), m[i - 1, j - 1] + diff);
		}
	}
	return m[string1.Length, string2.Length];
}

