# Islandora Field Values

## Overview

Islandora 7.x utility module that shows the unique values in the selected Solr field. To use it:

1. Go to `islandora/get_field_values`
1. Enter part of the Solr field name in the form field. If you don't know which version of the field to choose, you can't go wrong with the version ending in "_ms":
   ![The menu](docs/images/mods_fields.png)
1. Click on the "Submit" button to see the unique values in the selected field, along with an occurance count:
   ![The button](docs/images/values.png)

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
