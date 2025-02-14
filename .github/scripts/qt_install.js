function Controller() {
    installer.autoRejectMessageBoxes();
    installer.setMessageBoxAutomaticAnswer("OverwriteTargetDirectory", QMessageBox.Yes);
    installer.setMessageBoxAutomaticAnswer("installationError", QMessageBox.Ok);
    
    var components = ["qt.qt6.615.macos", "qt.tools.designer"];
    installer.setComponentsToInstall(components);
}

Controller.prototype.WelcomePageCallback = function() {
    gui.clickButton(buttons.NextButton);
}

// ... остальные стандартные обработчики ...
