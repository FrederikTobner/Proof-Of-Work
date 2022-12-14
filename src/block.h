#ifndef BLOCK_H
#define BLOCK_H

#ifdef __cplusplus
extern "C" {
#endif

#include "precompiled_header.h"

typedef struct
{
    size_t blockIndex;          // The index of the block in the chain
    uint32_t blockNonce;        // The nonce of the block (is incremented after each miningattempt)
    size_t dataAllocatedSize;   // The amount of allicated bytes of the dynamic data array
    size_t dataUsedSize;        // The amount of used bytes in the dynamic data array
    char const * data;          // The data (e.g. a sequence of transactions) that is stored in the block
    time_t blockTime;           // The time where the block was mined
    uint8_t * ownHash;          // The hashvalue of the current block
    uint8_t * previousHash;     // The hashvalue of the prevoius block
    uint8_t * merkleRoot;       // The merkle root that was calculated based on the data in the block
} block_t;

/// @brief Frees the dynamic memory previously used in the the block (ownhash and data) 
/// @param block The block where the contents are freed
void block_free(block_t block);

/// @brief Initializes a block with the specified data
/// @param block The block that is initialized
/// @param data The data that is stored in the block
/// @return 0 if sucessful
int block_init(block_t * block, char const * data);

/// @brief Mines a block with the specified difficulty - using proof of work
/// @param block The block that is mined
/// @param difficulty The difficulty of the mining process
void block_mine(block_t * block, uint32_t difficulty);


/// @brief Prints the contents of a block on the console
/// @param block The block that is printed
void block_print(block_t block);

#ifdef __cplusplus
}
#endif

#endif