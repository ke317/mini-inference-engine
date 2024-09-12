#ifndef TOKENIZER_H
#define TOKENIZER_H

typedef struct {
    char** vocab;
    float* vocab_scores;
    TokenIndex *sorted_vocab;
    int vocab_size;
    unsigned int max_token_length;
    unsigned char byte_pieces[512]; // stores all single-byte strings
} Tokenizer;

void build_tokenizer(Tokenizer* t, char* tokenizer_path, int vocab_size);
void free_tokenizer(Tokenizer* t);
char* decode(Tokenizer* t, int prev_token, int token);
void encode(Tokenizer* t, char *text, int8_t bos, int8_t eos, int *tokens, int *n_tokens);

#endif