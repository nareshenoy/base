from zipfile import ZipFile

def smart_open(filename, mode='r'):
    """
    Use this method to open files without worrying about the format.
    Handles .zip files currently.

    Opens in read mode by default.

    """
    if filename.endswith('.zip'):
        return ZipFile(filename, mode)

    return open(filename, mode)

