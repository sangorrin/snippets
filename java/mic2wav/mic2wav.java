/*
 * Build instructions:
 * $(JDKPATH)/bin/javac mic2wav.java
 * $(JDKPATH)/bin/java mic2wav
 */
import java.io.*;
import javax.sound.sampled.*;

public class mic2wav {

    /* Record sound with this sampling parameters */
    final static int SAMPLES_PER_SEC = 16000; /* e.g.: 16000 44100 88200 */
    final static int BITS_PER_SAMPLE = 8; /* e.g.: 8 or 16 bits/sample */
    final static int NUM_CHANNELS = 1; /* e.g.: 1 for mono, 2 for stereo */

    /* Seconds to record */
    final static int SECONDS = 5;

    public static void main(String[] args)
            throws IOException, LineUnavailableException {

        /* Modify the constants for a different audio format */
        AudioFormat format = new AudioFormat(SAMPLES_PER_SEC, BITS_PER_SAMPLE,
                                             NUM_CHANNELS, true, true);

        /* TargetDataLine represents the MIC input */
        TargetDataLine line = AudioSystem.getTargetDataLine(format);

        /* Use a dynamic array for storing the captured data */
        ByteArrayOutputStream captured = new ByteArrayOutputStream();

        /* We will fetch captured data in "chunks" from the line's buffer" */
        byte[] chunk = new byte[4096];
        int nbytes;

        /* START CAPTURING!! */
        line.open(format);
        line.start();

        while (captured.size() < (SAMPLES_PER_SEC*SECONDS)) {
            nbytes = line.read(chunk, 0, chunk.length);
            captured.write(chunk, 0, nbytes);
        }

        /* STOP CAPTURING */
        line.drain();
        line.close();

        /* Create a wav file to store the samples */
        File wav = new File("captured.wav");

        /* Copy the captured samples into a audioInputStream */
        byte[] captured_bytes = captured.toByteArray();
        ByteArrayInputStream inputstream =
                new ByteArrayInputStream(captured_bytes);
        AudioInputStream audioInputStream =
                new AudioInputStream(inputstream, format, captured.size());

        /* Write the samples into the WAV file */
        AudioSystem.write(audioInputStream, AudioFileFormat.Type.WAVE, wav);

        /* Housekeeping */
        audioInputStream.close();
        captured.close();
    }
}
