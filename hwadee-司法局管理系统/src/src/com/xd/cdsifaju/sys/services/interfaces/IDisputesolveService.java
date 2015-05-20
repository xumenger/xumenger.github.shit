package com.xd.cdsifaju.sys.services.interfaces;

import java.util.List;

import com.xd.cdsifaju.entities.Disputesolve;

public interface IDisputesolveService {
List<Disputesolve> list();
String add(Disputesolve ds);
}
