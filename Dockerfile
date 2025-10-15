FROM gcc:latest

WORKDIR /app

# Copier les fichiers source
COPY src/ ./src/
COPY Makefile .

# Compiler le programme complet (qui fait entiers + chaînes)
RUN make tri_complet

# Exécuter le programme complet
CMD ["./build/tri_complet"]