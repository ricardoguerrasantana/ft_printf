# Use the official GCC image as a base image
FROM gcc:latest

# Install dependencies
RUN apt-get update && \
    apt-get install -y \
    vim \
    # Install norminette dependencies
    python3 \
    python3-venv \
    python3-pip \
    python3-setuptools \
    pipx \
    # Install francinette dependencies
    curl \
    clang \     
    libbsd-dev \
    && rm -rf /var/lib/apt/lists/*

# Create a virtual environment and install norminette
RUN python3 -m venv /opt/venv && \
    /opt/venv/bin/pip install --upgrade pip setuptools && \
    /opt/venv/bin/pip install norminette

# Set the PATH to include the virtual environment
ENV PATH="/opt/venv/bin:$PATH"

# Install Francinette
RUN bash -c "$(curl -fsSL https://raw.github.com/xicodomingues/francinette/master/bin/install.sh)"

# Copy the local .vimrc into the container
COPY .vimrc /root/.vimrc
# COPY .bashrc /root/.bashrc
