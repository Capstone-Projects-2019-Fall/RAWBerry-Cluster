%%

% ./in/ pics were converted using Adobe DNG converter
a = dir(['./in/' '/*.dng']);
num_in = size(a, 1);

psnrs = zeros(num_in, 1);

for i = 1:num_in
    % Read in the files in the in and out dirs
    fnameIn = sprintf('in_%d.dng', i);
    fnameOut = sprintf('out_%d_fast.dng', i);
    pathIn = sprintf('./in/%s', fnameIn);
    pathOut = sprintf('./out/%s', fnameOut);
    fileIn = imread(pathIn);
    fileOut = imread(pathOut);

    % Get size of existing image A.
    [rowsIn, colsIn, numberOfColorChannelsIn] = size(fileIn);
    % Get size of existing image B.
    [rowsOut, colsOut, numberOfColorChannelsOut] = size(fileOut);
    
    % See if lateral sizes match.
    if rowsOut ~= rowsIn || colsIn ~= colsOut
        % Size of B does not match A, so resize B to match A's size.
        fileOut = imresize(fileOut, [rowsIn colsIn]);
    end
    
    % Record the PSNR calculations
    psnrs(i) = psnr(fileOut, fileIn);
end