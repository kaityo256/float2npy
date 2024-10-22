import numpy as np
from PIL import Image


def save_img(filename, data, row, column):
    img = Image.new("L", (row, column))
    pix = img.load()
    data = np.clip(0, 255, data * 255)
    for i in range(row):
        for j in range(column):
            pix[i, j] = int(data[i][j])
    img.save(filename)


def load_data(filename, row, column):
    data = np.fromfile(filename, dtype=np.float32)
    data = data.reshape((row, column))
    return data


def main():
    row = 218
    column = 178
    data = load_data("data.dat", row, column)
    save_img("output.png", data, row, column)


if __name__ == "__main__":
    main()
