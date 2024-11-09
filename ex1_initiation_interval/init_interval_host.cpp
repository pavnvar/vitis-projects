#include <iostream>
void Example0(float const *a_mem, float const *b_mem, float *c_mem);


int main(){
	float a_mem[1024];
	float b_mem[1024];
	float c_mem[1024];
	for(int i = 0; i<1024; i++) {
		a_mem[i] = static_cast<float>(i);
		b_mem[i] = static_cast<float>(1024 - i);
	}
	Example0(a_mem, b_mem, c_mem);
	for (int i = 0; i < 10; ++i) {
	    std::cout << "c_mem[" << i << "] = " << c_mem[i] << std::endl;
	 }
	return 0;
}

