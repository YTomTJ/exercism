public static class TelemetryBuffer
{
    //4_294_967_296	9_223_372_036_854_775_807	long
    //2_147_483_648	4_294_967_295	uint
    //65_536	2_147_483_647	int
    //0	65_535	ushort
    //-32_768	-1	short
    //-2_147_483_648	-32_769	int
    //-9_223_372_036_854_775_808	-2_147_483_649	long

    public static byte[] ToBuffer(long reading)
    {
        sbyte sign = 1;
        byte[] arr;
        if (reading > uint.MaxValue) { // long
            arr = BitConverter.GetBytes((long)reading);
            sign = -1;
        }
        else if (reading > int.MaxValue) { // uint
            arr = BitConverter.GetBytes((uint)reading);
        }
        else if (reading > ushort.MaxValue) { // int
            arr = BitConverter.GetBytes((int)reading);
            sign = -1;
        }
        else if (reading >= 0) { // ushort
            arr = BitConverter.GetBytes((short)reading);
        }
        else if (reading >= short.MinValue) { // short
            arr = BitConverter.GetBytes((short)reading);
            sign = -1;
        }
        else if (reading >= int.MinValue) { // int
            arr = BitConverter.GetBytes((int)reading);
            sign = -1;
        }
        else {
            arr = BitConverter.GetBytes((long)reading);
            sign = -1;
        }
        byte[] buf = new byte[9];
        Array.Copy(arr, 0, buf, 1, arr.Length);
        buf[0] = (byte)(sign > 0 ? arr.Length : (256 - arr.Length));
        return buf;
    }

    public static long FromBuffer(byte[] buffer)
    {
        int n = buffer[0];
        if (n == 8 || n == 256 - 8) {
            return BitConverter.ToInt64(new Span<byte>(buffer, 1, 256 - n));
        }
        else if (n == 4 || n == 256 - 4) {
            return (n > 128) ?
                BitConverter.ToInt32(new Span<byte>(buffer, 1, 256 - n))
              : BitConverter.ToUInt32(new Span<byte>(buffer, 1, n));
        }
        else if (n == 2 || n == 256 - 2) {
            return (n > 128) ?
                BitConverter.ToInt16(new Span<byte>(buffer, 1, 256 - n))
              : BitConverter.ToUInt16(new Span<byte>(buffer, 1, n));
        }
        return 0;
    }
}
