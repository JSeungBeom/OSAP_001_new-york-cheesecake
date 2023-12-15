FROM ubuntu:latest
LABEL purpose="OSAP final project"
LABEL author="Jiwon Choi"
LABEL team="New york cheesecake"
COPY ./ ./

WORKDIR ./'AVL Tree'/'AVL Tree'/build

CMD ["./mainApp"]

