% This script performs various statistical analyses on SP1 calibration data
% to determine whether the mean Acc calibration values can be used to
% calibrate every unit
%
% Author: Brett Nicholas
% Created: 7/15/15
close all 
clear all

%% Obtain data and load into matrix 

% Call shell script that aggregates all data into one .CSV file
if ( (isunix) || (ismac))
    s = system('./read_calib_data.sh');
end 

% Read in data from file
ACC_vals = csvread('ACC_Values.csv'); 

% Initialize matrices to store data 
h = length(ACC_vals(:,1)); 
A = zeros(3,3,ceil((h-1)/3)); % Holds ACC matrix for each test
ACC_avgs = zeros(3,3); % Holds average ACC Data 

% Construct 3D matrix 
done = 0; 
cols=1;
P=1;
while (done == 0) 
    for M = 1:3
        for N=1:3
            A(M,N,P) = ACC_vals(cols,N);
        end
        
        cols = cols + 1;
        
        if ( cols == h )
            done = 1;
            break;
        end 
    end
    P=P+1;
end

%% Statistical analysis on existing ACC matrix values
num_tests = length(A(1,1,:));

% Calculate range matrix
Range = zeros(M,N);
for M=1:3
    for N=1:3
        Range(M,N) = abs( max(A(M,N,:)) - min(A(M,N,:)) ); 
    end
end

% Calculate mean for all tests 
for M=1:3
    for N=1:3
        ACC_avgs(M,N) = mean( A(M,N,:) ); 
    end 
end

% Calculate STD Dev for each matrix element for all tests 
S_dev = zeros(3,3);
for M=1:3
    for N=1:3
        S_dev(M,N) = std( A(M,N,:) ); 
    end 
end

% Calculate uncertainty in measurement (range based)
U_meas = zeros(M,N);
for M=1:3
    for N=1:3
        U_meas(M,N) = Range(M,N) / 2; 
    end
end

% Calculate uncertainty in the mean (from range)
U_mean = zeros(M,N);
for M=1:3
    for N=1:3
        U_mean(M,N) = Range(M,N) / (2 * sqrt(num_tests)); 
    end
end

% Calculate uncertainty in the mean (from SD)
U_mean_SD = zeros(M,N);
for M=1:3
    for N=1:3
        U_mean_SD(M,N) = S_dev(M,N) / sqrt(num_tests); 
    end
end

%% Statistics for Euler angles

% calculate euler angles for everyy rotation matrix
Euler_angles = zeros(1,3,num_tests);
for i=1:num_tests
        [x, y, z] = rot2euler( A(:,:,i) ); % Get angle for each row
        Euler_angles(:,:,i) = [x y z]; 
end
Euler_angles = Euler_angles .* (180/pi)

% calculate Std deviations for each euler angle (roll,pitch,yaw)
S_dev1_angles_in_rads = zeros(1,3);
for N=1:3
        S_dev1_angles_in_rads(:,N) = std( Euler_angles(:,N,:) ); 
end
S_dev1_angles_in_deg = S_dev1_angles_in_rads .* (180/pi); % in degrees


%% display results
disp(' '); disp(' ')
disp('RESULTS')
disp('------------------------------------')
ACC_RANGES = table(Range) % range
disp('------------------------------------')
MEAN = table(ACC_avgs) % mean
disp('------------------------------------')
STANDARD_DEVIATION = table(S_dev) % std_dev
disp('------------------------------------')
UNCERTAINTY = table(U_meas) % uncertai
disp('------------------------------------')
UNCERTAINTY_IN_MEAN_RANGE = table(U_mean) %uncertainty in mean (range)
disp('------------------------------------')
UNCERTAINTY_IN_MEAN_SD = table(U_mean_SD) %uncertainty in mean (SD)
disp('------------------------------------')
STANDARD_DEVIATION_EULER_ANGLES__IN_RADS = table(S_dev1_angles_in_rads) 
STANDARD_DEVIATION_EULER_ANGLES__IN_DEG = table(S_dev1_angles_in_deg) 

% Plotting 
figure
h = histogram(Euler_angles(:,2,:))
title('Euler Angle (y/roll) Histogram for Calibration Rotation Matrix') 
xlabel('Deviation from the mean (deg)')
ylabel('Number of tests')




