# Islandora Field Values

Islandora 7.x utility module that shows the unique values in the selected Solr field.

## Usage

To use it:

1. Go to `islandora/get_field_values`
1. Enter part of the Solr field name in the form field. If you don't know which version of the field to choose, you can't go wrong with the version ending in "_ms":
   ![The menu](docs/images/mods_fields.png)
1. Click on the "Submit" button to see the unique values in the selected field, along with an occurance count:
   ![The button](docs/images/values.png)

Clicking on the link will perform a search for all the objects with that value.

Note that the text that appears in results is not necessarily identical to the value of the field; values that contain HTML tags have the tags stripped so they do not interfere with rendering the results list.

## Drush command

This module also comes with a Drush command. Here's an example:

`drush islandora-field-values-get --fieldname=mods_abstract_ms --output_file=/tmp/output.txt`

The output is a tab-delimited file (first column in field values, second column is occurance count):

```
Unique values for Solr field mods_genre_ms (210 unique values)

Postcards       34940
Text    12940
Editorial cartoons      11341
Photographs     6049
photographs     5992
Image   5798
Painting & Drawing      1733
%value  1176
Records (Documents)     1139
Architecture: built works       1032
Architecture    1019
Interviews (Sound recordings)   836
Oral histories  747
text    616
Painting: paintings     583
Letter/Memo     567
Sculpture: sculpture (visual work)      546
Photography: photographs        510
Sculpture       497
```

Add `--remove_line_breaks` if you want to remove line breaks from field values so they fit nicely on a single rown in the output.


## Installation

1. `git clone https://github.com/mjordan/islandora_field_values.git`
1. `drush en -y islandora_get_csv` or enable it at Admin > Modules.


## Configuration

None, other than to assign users the required "Get unique Solr field values" permission.

## Dependencies

* [Islandora](https://github.com/Islandora/islandora)
* [Islandora Solr](https://github.com/Islandora/islandora_solr_search)

## License

* [GPLv3](http://www.gnu.org/licenses/gpl-3.0.txt)
