import React from 'react';
import { Constants, Location, Permissions } from 'expo'

export default async function findMe() {

	let errorMessage = null;
	let location = null;
	let { status } = await Permissions.askAsync(Permissions.LOCATION);

	if (status !== 'granted') {
			errorMessage: 'Permissoin to access location was denied'
	}

	location = await Location.getCurrentPositionAsync ({});

	if (errorMessage) {
		return errorMessage;
	} else if (location) {
		return location.coords;
	} else {
		return 'error tmp'
	}
}
