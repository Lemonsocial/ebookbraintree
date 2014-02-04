<?php
require_once('braintree-php-2.10.0/lib/Braintree.php');

Braintree_Configuration::environment();
Braintree_Configuration::merchantId();
Braintree_Configuration::publicKey();
Braintree_Configuration::privateKey();
?>
