void InitiationInterval(float const *a_mem, float const *b_mem, float *c_mem);
void Example0(float const *a_mem, float const *b_mem, float *c_mem);
constexpr int N = 1024;


void Example0(float const *a_mem, float const *b_mem, float *c_mem) {
  #pragma HLS INTERFACE m_axi port=a_mem offset=slave bundle=gmem0
  #pragma HLS INTERFACE m_axi port=b_mem offset=slave bundle=gmem1
  #pragma HLS INTERFACE m_axi port=c_mem offset=slave bundle=gmem2
  #pragma HLS INTERFACE s_axilite port=a_mem bundle=control
  #pragma HLS INTERFACE s_axilite port=b_mem bundle=control
  #pragma HLS INTERFACE s_axilite port=c_mem bundle=control
  #pragma HLS INTERFACE s_axilite port=return
  InitiationInterval(a_mem, b_mem, c_mem);
}

void InitiationInterval(float const *a_mem, float const *b_mem, float *c_mem) {
  for (int i = 0; i < N; ++i) {
    const auto a = a_mem[i];
    const auto b = b_mem[i];
    // -------------------------
    // Try changing the target initiation interval (II) and re-running HLS.
    // Notice what happens to the total number of cycles to completion, and to
    // the number of adders instantiated.
    #pragma HLS PIPELINE II=1
    float c = (a + b) * (a - b);
    // -------------------------
    c_mem[i] = c;
  }
}
