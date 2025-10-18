FROM gcc:latest

WORKDIR /app

# Copier les fichiers source
COPY src/ ./src/
COPY Makefile.linux ./Makefile

# Compiler les deux programmes
RUN make all

# Créer des liens symboliques pour permettre l'exécution individuelle
RUN ln -s /app/build/tri_bulles /usr/local/bin/tri_bulles && \
    ln -s /app/build/tri_chaines /usr/local/bin/tri_chaines

# Créer un script d'entrée pour exécuter les deux programmes
RUN echo '#!/bin/bash' > /app/run.sh && \
    echo 'echo "=== Exécution du tri à bulles ==="' >> /app/run.sh && \
    echo './build/tri_bulles' >> /app/run.sh && \
    echo 'echo ""' >> /app/run.sh && \
    echo 'echo "=== Exécution du tri de chaînes ==="' >> /app/run.sh && \
    echo './build/tri_chaines' >> /app/run.sh && \
    chmod +x /app/run.sh

# Exécuter les deux programmes par défaut
CMD ["/app/run.sh"]