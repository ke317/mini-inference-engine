#ifndef CHAT_H
#define CHAT_H

#include "transformer.h"
#include "tokenizer.h"
#include "sampler.h"

void chat(Transformer *transformer, Tokenizer *tokenizer, Sampler *sampler, char *cli_user_prompt, char *cli_system_prompt, int steps);

#endif