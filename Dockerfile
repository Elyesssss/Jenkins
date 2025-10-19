FROM gcc:latest

WORKDIR /app

# Copier les fichiers source et le Makefile
COPY src/ ./src/
COPY tests/ ./tests/
COPY Makefile ./Makefile

# Compiler les deux programmes
RUN make all

# Script pour exécuter les deux programmes
RUN echo '#!/bin/bash' > /app/run.sh && \
    echo 'echo "=== Exécution du tri à bulles ==="' >> /app/run.sh && \
    echo './build/tri_bulles' >> /app/run.sh && \
    echo 'echo ""' >> /app/run.sh && \
    echo 'echo "=== Exécution du tri de chaînes ==="' >> /app/run.sh && \
    echo './build/tri_chaines' >> /app/run.sh && \
    chmod +x /app/run.sh

CMD ["/app/run.sh"]