import torch
import torch.nn as nn
import torch.nn.functional as F
import torch.optim as optim

import helper.modelHandler as model
import helper.dataHandler as data

import torch.onnx


class denseNet(nn.Module):
    def __init__(self):
        super().__init__()
        self.fc1 = nn.Linear(784, 32)
        self.fc2 = nn.Linear(32, 10)

    def forward(self, x):
        x = torch.flatten(x, 1)  # flatten all dimensions except batch
        x = F.relu(self.fc1(x))
        x = self.fc2(x)
        return x


if __name__ == '__main__':

    batch_size = 4

    train_loader, test_loader = data.load_mnist_dataset(batch_size)

    """
        Uncomment this section to display training images
        data.show_images(train_loader, batch_size)
    """

    net = denseNet()

    criterion = nn.CrossEntropyLoss()
    optimizer = optim.SGD(net.parameters(), lr=0.001, momentum=0.9)
    n_epochs  = 2

    net = model.train_network(net, train_loader, optimizer, criterion, n_epochs)

    model.test_network(net, test_loader)

    # Set the model to be in 'inference' mode
    net.eval()

    # Input to the model
    x = torch.randn(batch_size, 1, 28, 28, requires_grad=True)
    torch_out = net(x)

    # Export the model
    torch.onnx.export(net,                     # model being run
                    x,                         # model input (or a tuple for multiple inputs)
                    "simpleMNIST.onnx",        # where to save the model (can be a file or file-like object)
                    export_params=True,        # store the trained parameter weights inside the model file
                    opset_version=10,          # the ONNX version to export the model to
                    do_constant_folding=True,  # whether to execute constant folding for optimization
                    input_names = ['input'],   # the model's input names
                    output_names = ['output'], # the model's output names
                    dynamic_axes={'input' : {0 : 'batch_size'},    # variable length axes
                                  'output' : {0 : 'batch_size'}})