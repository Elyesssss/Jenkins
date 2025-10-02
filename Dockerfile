FROM gcc:latest

WORKDIR /app

# Copier les fichiers source
COPY src/ ./src/
COPY Makefile .

# Compiler le programme
RUN make

# Exécuter le programme au démarrage
CMD ["./build/tri_bulles"]