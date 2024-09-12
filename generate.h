#ifndef GENERATE_H
#define GENERATE_H

#include "transformer.h"
#include "tokenizer.h"
#include "sampler.h"

void generate(Transformer *transformer, Tokenizer *tokenizer, Sampler *sampler, char *prompt, int steps);

#endif