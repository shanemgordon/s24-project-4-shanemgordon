#include "algorithms/fcfs/fcfs_algorithm.hpp"

#include <cassert>
#include <stdexcept>
#define FMT_HEADER_ONLY
#include "utilities/fmt/format.h"

/*
    Here is where you should define the logic for the FCFS algorithm.
*/
using namespace std;
FCFSScheduler::FCFSScheduler(int slice) {
    if (slice != -1) {
        throw("FCFS must have a timeslice of -1");
    }
}

std::shared_ptr<SchedulingDecision> FCFSScheduler::get_next_thread() {
        // Should simply pop the queue and not pre-empt the result
        shared_ptr<SchedulingDecision> newDecision = make_shared<SchedulingDecision>();
        if(size() == 0){
            newDecision->explanation = "Ready Queue empty, returning nullptr";
            newDecision->thread = nullptr;
            newDecision->time_slice = -1;
            return newDecision;
        } 
        newDecision->time_slice = -1; //Non Pre-emptive algorithm
        char buffer [200];
        sprintf(buffer,"Selected from %i threads. Will run to completion of burst.", (static_cast<int> (size())));
        newDecision->explanation = buffer;
        newDecision->thread = readyQueue.front();
        readyQueue.pop();
        return newDecision;
}

void FCFSScheduler::add_to_ready_queue(std::shared_ptr<Thread> thread) {

        //May potentially want to regulate input here
        
        readyQueue.push(thread); //Add thisThread to the queue

}

size_t FCFSScheduler::size() const {
        return readyQueue.size();
}
