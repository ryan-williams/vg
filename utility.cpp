#include "utility.hpp"

namespace vg {

string reverse_complement(const string& seq) {
    string rc;
    rc.assign(seq.rbegin(), seq.rend());
    for (auto& c : rc) {
        switch (c) {
        case 'A': c = 'T'; break;
        case 'T': c = 'A'; break;
        case 'G': c = 'C'; break;
        case 'C': c = 'G'; break;
        case 'N': c = 'N'; break;
        default: break;
        }
    }
    return rc;
}

int get_thread_count(void) {
    int thread_count = 1;
#pragma omp parallel
    {
#pragma omp master
        thread_count = omp_get_num_threads();
    }
    return thread_count;
}

}
