package pitch2note;

public class AutoCorrelation {

	public static double[] wave_to_autocorr(byte[] wave)
	{
		double[] autocorr = new double[wave.length];
		
		// Sum(wave[i]*wave[i-off])
		for(int offset=0; offset < wave.length; offset++) {
			autocorr[offset] = 0;
			for(int i=offset; i < wave.length; i++) {
				autocorr[offset] = autocorr[offset] + 
						wave[i]*wave[i-offset] / wave.length;
			}
		}

		// Normalize dividing by the lenght and by the maximum (offet=0)
		double max = autocorr[0];
		for(int i=0; i < autocorr.length; i++) {
			autocorr[i] = autocorr[i] / max;
		}
		
		return autocorr;
	}

}
