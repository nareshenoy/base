from tools.decorators import memoize
from tools.files      import smart_open

def get_data(zip_filename, file_name):
    fh = smart_open(zip_filename)
    data = fh.read(file_name)
    all_data = {}
    for line in data.split('\n'):
        line = line.rstrip()
        data_in_line = line.split('\t')
        # Remove trailing whitespace
        #data_in_line = data_in_line[:-1]
        if data_in_line == ['']:
            continue
        obs_number, class_id, attrs = int(data_in_line[0]), data_in_line[1], data_in_line[2:]
        attrs = map(lambda x: float(x), attrs)
        if class_id in all_data:
            all_data[class_id].append(attrs)
        else:
            all_data[class_id] = [attrs]

    return all_data

COL_NUM_2_OUTLIER_VALUE = { 
                                (19, 20, 
                                 21, 43, 
                                 44, 45) : (999.0,),
                                (28, 54) : (9999.0,)
                          }   

@memoize
def get_col_outlier_value(col_num):

    outlier_value = None
    for k in COL_NUM_2_OUTLIER_VALUE:
        if col_num in k:
            outlier_value = COL_NUM_2_OUTLIER_VALUE[k]
            break
    return outlier_value

@memoize
def get_cols_with_outliers():

    cols_with_outliers = []
    for key in COL_NUM_2_OUTLIER_VALUE:
        cols_with_outliers.extend(list(key))

    return cols_with_outliers

