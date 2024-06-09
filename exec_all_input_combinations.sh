rm results.csv
touch results.csv
echo "input;noise;config;input_snr;output_snr;input_mse;output_mse;execution_time" > results.csv

./main.exe "speech-librivox-0005" "white_noise_5db" "sym8" "5" "soft" "0.25" "1"
./main.exe "speech-librivox-0010" "white_noise_5db" "sym8" "3" "soft" "0.5" "0.6"
./main.exe "speech-librivox-0034" "white_noise_5db" "sym8" "4" "soft" "0.5" "0.6"
./main.exe "speech-librivox-0062" "white_noise_5db" "sym8" "3" "soft" "0.5" "0.8"
./main.exe "speech-librivox-0082" "white_noise_5db" "sym8" "5" "soft" "0.25" "0.8"
./main.exe "speech-librivox-0117" "white_noise_5db" "sym8" "4" "soft" "0.5" "0.8"

./main.exe "speech-librivox-0005" "white_noise_10db" "sym8" "4" "soft" "0.25" "1"
./main.exe "speech-librivox-0010" "white_noise_10db" "sym8" "3" "soft" "0.25" "1"
./main.exe "speech-librivox-0034" "white_noise_10db" "sym8" "3" "soft" "0.25" "1"
./main.exe "speech-librivox-0062" "white_noise_10db" "sym8" "3" "soft" "0.75" "0.4"
./main.exe "speech-librivox-0082" "white_noise_10db" "sym8" "5" "soft" "0.75" "0.2"
./main.exe "speech-librivox-0117" "white_noise_10db" "sym8" "4" "soft" "0.5" "0.6"

./main.exe "speech-librivox-0005" "noise-free-sound-0001" "db2" "5" "soft" "1" "1"
./main.exe "speech-librivox-0010" "noise-free-sound-0001" "sym2" "5" "soft" "1" "1"
./main.exe "speech-librivox-0034" "noise-free-sound-0001" "sym2" "5" "soft" "1" "1"
./main.exe "speech-librivox-0062" "noise-free-sound-0001" "sym2" "5" "soft" "1" "1"
./main.exe "speech-librivox-0082" "noise-free-sound-0001" "sym2" "5" "soft" "0.75" "1"
./main.exe "speech-librivox-0117" "noise-free-sound-0001" "sym2" "5" "soft" "1" "1"

./main.exe "speech-librivox-0005" "noise-free-sound-0271" "sym8" "5" "soft" "1" "1"
./main.exe "speech-librivox-0010" "noise-free-sound-0271" "db8" "5" "soft" "1" "1"
./main.exe "speech-librivox-0034" "noise-free-sound-0271" "db8" "5" "soft" "1" "1"
./main.exe "speech-librivox-0062" "noise-free-sound-0271" "sym8" "5" "soft" "1" "1"
./main.exe "speech-librivox-0082" "noise-free-sound-0271" "db2" "5" "soft" "0.5" "0.8"
./main.exe "speech-librivox-0117" "noise-free-sound-0271" "db5" "5" "soft" "1" "1"

./main.exe "speech-librivox-0005" "noise-free-sound-0278" "sym5" "5" "soft" "1" "1"
./main.exe "speech-librivox-0010" "noise-free-sound-0278" "db5" "5" "soft" "1" "1"
./main.exe "speech-librivox-0034" "noise-free-sound-0278" "db5" "5" "soft" "1" "1"
./main.exe "speech-librivox-0062" "noise-free-sound-0278" "db2" "5" "soft" "1" "1"
./main.exe "speech-librivox-0082" "noise-free-sound-0278" "db2" "5" "soft" "0.5" "1"
./main.exe "speech-librivox-0117" "noise-free-sound-0278" "db2" "5" "soft" "1" "1"

./main.exe "speech-librivox-0005" "noise-free-sound-0165" "db8" "5" "soft" "1" "1"
./main.exe "speech-librivox-0010" "noise-free-sound-0165" "db5" "5" "soft" "1" "1"
./main.exe "speech-librivox-0034" "noise-free-sound-0165" "db8" "5" "soft" "1" "1"
./main.exe "speech-librivox-0062" "noise-free-sound-0165" "db2" "5" "soft" "1" "1"
./main.exe "speech-librivox-0082" "noise-free-sound-0165" "sym2" "5" "soft" "0.5" "0.6"
./main.exe "speech-librivox-0117" "noise-free-sound-0165" "db2" "5" "soft" "1" "1"