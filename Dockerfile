FROM gcc:latest

WORKDIR /app

# Copier les fichiers source
COPY src/ ./src/
COPY tests/ ./tests/
COPY Makefile .

# Compiler tous les programmes
RUN make all

# Créer un script pour exécuter les deux programmes
RUN echo '#!/bin/bash' > /app/run_all.sh && \
    echo 'echo "==================================="' >> /app/run_all.sh && \
    echo 'echo "   TRI D'\''ENTIERS (BULLES)"' >> /app/run_all.sh && \
    echo 'echo "==================================="' >> /app/run_all.sh && \
    echo './build/tri_bulles' >> /app/run_all.sh && \
    echo 'echo ""' >> /app/run_all.sh && \
    echo 'echo "==================================="' >> /app/run_all.sh && \
    echo 'echo "   TRI DE CHAÎNES ALPHANUMÉRIQUES"' >> /app/run_all.sh && \
    echo 'echo "==================================="' >> /app/run_all.sh && \
    echo './build/tri_chaines' >> /app/run_all.sh && \
    chmod +x /app/run_all.sh

# Exécuter le script au démarrage (par défaut tri d'entiers)
CMD ["./build/tri_bulles"]

# Pour exécuter les deux programmes :
# docker run --rm <image_name> ./run_all.sh

# Pour exécuter le tri de chaînes :
# docker run --rm <image_name> ./build/tri_chaines