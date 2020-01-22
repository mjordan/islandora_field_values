# Islandora Field Values

Islandora 7.x utility module that shows the unique values in the selected Solr field.

## Usage

To use it:

1. Go to `islandora/get_field_values`
1. Enter part of the Solr field name in the form field. If you don't know which version of the field to choose, you can't go wrong with the version ending in "_ms":
   ![The menu](docs/images/mods_fields.png)
1. Click on the "Submit" button to see the unique values in the selected field, along with an occurance count:
   ![The button](docs/images/values.png)


## Drush command

This module also comes with a Drush command. Here's an example:

`drush islandora-field-values-get --fieldname=mods_abstract_ms --output_file=/tmp/output.txt`.

The output is a tab-delimited file (first column in field values, second column is occurance count):

```
Unique values for Solr field mods_abstract_ms (24 unique values)

An aerial view of a wharf at Manson's Landing, B.C. A few sea planes are shown parked by the wharf.     2
The Ruskin Power Plant near Mission City, B.C. A bridge is shown leading to the power plant.    2
A Bill Bose ox team in front of the Clinton Hotel on its way to Barkerville, B.C.       1
A dog sled team in Atlin, B.C.  1
A street in Barkerville, B.C. Some storefronts and automobiles are shown.       1
A street in Qualicum Beach, B.C. Some storefronts and automobiles are shown.    1
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
