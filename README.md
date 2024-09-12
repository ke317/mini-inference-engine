# Mini LLM Inference Engine in C

This project presents a minimalist inference engine for processing Llama 2 language models, written entirely in C. It is designed to run large language models efficiently on devices with limited resources.

## Features
- **Lightweight Engine**: Implements a lean inference mechanism tailored for Llama 2 language models, enabling their deployment and execution on resource-constrained environments.
- **Core Components**: Includes a custom transformer architecture, tokenizer, and sampling strategies. The engine supports diverse functionalities like text generation and interactive chat modes.
- **Performance Optimization**: Utilizes advanced techniques to enhance performance, including:
  - Memory mapping to reduce I/O overhead.
  - OpenMP for multi-threading and parallel computation.
  - Optimized matrix operations for faster computation without compromising accuracy.
- **Real-time Inference**: Achieves real-time inference capabilities on consumer-grade hardware, making advanced natural language processing accessible on everyday devices.



### Installation

1. Clone the repository:
   ```bash
   git clone https://github.com/yourusername/simple-inference-engine.git
   ```

2. Navigate to the project directory:
   ```bash
   cd simple-inference-engine
   ```

### Running 

The project includes several compilation options:

1. Standard compilation with optimization:
   ```bash
   make run
   ./main
   ```


2. OpenMP parallel processing:
   ```bash
   make omp
   ./main_omp
   ```





