#include "generate.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void generate(Transformer *transformer, Tokenizer *tokenizer, Sampler *sampler, char *prompt, int steps) {
    char *empty_prompt = "";
    if (prompt == NULL) { prompt = empty_prompt; }

    int num_prompt_tokens = 0;
    int* prompt_tokens = (int*)malloc((strlen(prompt)+3) * sizeof(int));
    if (prompt_tokens == NULL) {
        fprintf(stderr, "Failed to allocate memory\n");
        exit(EXIT_FAILURE);
    }
    encode(tokenizer, prompt, 1, 0, prompt_tokens, &num_prompt_tokens);
    if (num_prompt_tokens < 1) {
        fprintf(stderr, "Error: at least 1 prompt token expected\n");
        free(prompt_tokens);
        exit(EXIT_FAILURE);
    }

    long start = 0;
    int next;
    int token = prompt_tokens[0];
    int pos = 0;
    while (pos < steps) {
        float* logits = forward(transformer, token, pos);
        if (pos < num_prompt_tokens - 1) {
            next = prompt_tokens[pos + 1];
        } else {
            next = sample(sampler, logits);
        }
        pos++;

        if (next == 1) { break; } // 遇到BOS token就结束

        char* piece = decode(tokenizer, token, next);
        safe_printf(piece);
        fflush(stdout);
        token = next;

        if (start == 0) { start = time_in_ms(); }
    }
    printf("\n");

    if (pos > 1) {
        long end = time_in_ms();
        fprintf(stderr, "Generation speed: %.2f tokens/s\n", (pos-1) / (double)(end-start)*1000);
    }

    free(prompt_tokens);
}