import java.util.Random;

class MatrixMultiplication extends Thread {
    private final int[][] A, B, C;
    private final int row;

    public MatrixMultiplication(int[][] A, int[][] B, int[][] C, int row) {
        this.A = A;
        this.B = B;
        this.C = C;
        this.row = row;
    }

    @Override
    public void run() {
        int n = B[0].length;
        int m = B.length;
        for (int j = 0; j < n; j++) {
            C[row][j] = 0;
            for (int k = 0; k < m; k++) {
                C[row][j] += A[row][k] * B[k][j];
            }
        }
    }
}

public class Main {
    public static void main(String[] args) throws InterruptedException {
        int size = 1000; // 🔥 Increase to 2000+ if you want more stress
        int[][] A = new int[size][size];
        int[][] B = new int[size][size];
        int[][] C = new int[size][size];
        Random rand = new Random();

        // Initialize matrices with random values
        for (int i = 0; i < size; i++)
            for (int j = 0; j < size; j++) {
                A[i][j] = rand.nextInt(100);
                B[i][j] = rand.nextInt(100);
            }

        // Measure time
        long startTime = System.currentTimeMillis();

        // Create threads for each row
        Thread[] threads = new Thread[size];
        for (int i = 0; i < size; i++) {
            threads[i] = new MatrixMultiplication(A, B, C, i);
            threads[i].start();
        }

        // Wait for all threads to finish
        for (int i = 0; i < size; i++) {
            threads[i].join();
        }

        long endTime = System.currentTimeMillis();
        System.out.println("✅ Matrix multiplication completed.");
        System.out.println("⏱️ Time taken: " + (endTime - startTime) + " ms");
    }
}
