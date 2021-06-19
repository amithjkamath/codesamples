import torch
import torch.nn as nn
import torch.nn.functional as F
import torch.optim as optim

import helper.modelHandler as model
import helper.dataHandler as data


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