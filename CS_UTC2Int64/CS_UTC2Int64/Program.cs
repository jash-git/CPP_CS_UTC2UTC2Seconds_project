using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CS_UTC2Int64
{
    class Program
    {
        static void Pause()
        {
            Console.Write("Press any key to continue...");
            Console.ReadKey(true);
        }
        static void Main(string[] args)
        {
            /*
            //https://docs.microsoft.com/zh-tw/dotnet/api/system.datetimeoffset.fromunixtimeseconds?view=net-5.0
            DateTimeOffset offset = DateTimeOffset.FromUnixTimeSeconds(20);
            Console.WriteLine("DateTimeOffset = {0}", offset);
            Console.WriteLine("DateTimeOffset (other format) = {0:dd} {0:y}, {0:hh}:{0:mm}:{0:ss}", offset);
            */

            /*        
            //https://docs.microsoft.com/zh-tw/dotnet/api/system.datetimeoffset.tounixtimeseconds?view=net-5.0
            DateTimeOffset dto = new DateTimeOffset(1970, 1, 1, 0, 0, 0, TimeSpan.Zero);
            Console.WriteLine("{0} --> Unix Seconds: {1}", dto, dto.ToUnixTimeSeconds());

            dto = new DateTimeOffset(1969, 12, 31, 23, 59, 0, TimeSpan.Zero);
            Console.WriteLine("{0} --> Unix Seconds: {1}", dto, dto.ToUnixTimeSeconds());

            dto = new DateTimeOffset(1970, 1, 1, 0, 1, 0, TimeSpan.Zero);
            Console.WriteLine("{0} --> Unix Seconds: {1}", dto, dto.ToUnixTimeSeconds());
            */

            DateTimeOffset dto = new DateTimeOffset(DateTime.Now);
            Console.WriteLine("{0} --> Unix Seconds: {1}", dto, dto.ToUnixTimeSeconds());//long
            Console.WriteLine("{0} --> Unix Milliseconds: {1}", dto, dto.ToUnixTimeMilliseconds());//long

            Pause();
        }
    }
}
