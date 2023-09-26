#ifndef __LOCATE_NODES_H__
#define __LOCATE_NODES_H__

#include <attributes.h>  //For __mram_ptr
#include <stdint.h>   //Fixed size integers
#include <stdbool.h>  //Booleans

#include "../common/common.h"

//Struct to store informations about one unique node (this speeds up the triangle counting)
typedef struct{
    uint32_t id;
    int32_t index_in_sample;
} node_loc_t;

//Determine the location of each unique node inside the sample, counting also the number of neighbors of that node
//Returns the number of unique nodes
uint32_t node_locations(__mram_ptr edge_t* sample, uint32_t edges_in_sample, __mram_ptr void* AFTER_SAMPLE_HEAP_POINTER, void* wram_buffer_ptr);

//Write node locations to the MRAM
void write_nodes_loc(uint32_t* nodes_loc_buffer_index, node_loc_t* nodes_loc_buffer_wram, __mram_ptr node_loc_t* AFTER_SAMPLE_HEAP_POINTER, bool last_write);

//Read new edges from the sample
uint32_t read_from_sample(__mram_ptr edge_t* sample, uint32_t edges_in_sample, edge_t* sample_buffer_wram, uint32_t* previous_node_id, uint32_t* edges_read);

//Debug function to know the information about the locations of the unique nodes
void print_node_locations(uint32_t number_of_nodes, __mram_ptr void* AFTER_SAMPLE_HEAP_POINTER);

#endif /* __LOCATE_NODES_H__ */